#include <gazebo/common/Plugin.hh>
#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/Model.hh>
#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>

#include <memory>
#include <thread>

namespace gazebo
{
class WanderbotMotionPlugin : public ModelPlugin
{
public:
  void Load(physics::ModelPtr model, sdf::ElementPtr) override
  {
    model_ = model;

    if (!rclcpp::ok()) {
      rclcpp::init(0, nullptr);
    }

    node_ = rclcpp::Node::make_shared("wanderbot_motion_plugin");
    cmd_vel_sub_ = node_->create_subscription<geometry_msgs::msg::Twist>(
      "cmd_vel", 10,
      [this](const geometry_msgs::msg::Twist::SharedPtr msg) {
        last_cmd_ = *msg;
      });

    executor_ = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
    executor_->add_node(node_);
    spinner_ = std::thread([this]() {executor_->spin();});

    update_connection_ = event::Events::ConnectWorldUpdateBegin(
      std::bind(&WanderbotMotionPlugin::OnUpdate, this, std::placeholders::_1));
  }

  void OnUpdate(const common::UpdateInfo &)
  {
    // Do not call spin_once() here because the executor is already running in its own thread.
    model_->SetLinearVel(ignition::math::Vector3d(last_cmd_.linear.x, 0.0, 0.0));
    model_->SetAngularVel(ignition::math::Vector3d(0.0, 0.0, last_cmd_.angular.z));
  }

  ~WanderbotMotionPlugin() override
  {
    if (executor_) {
      executor_->cancel();
    }
    if (spinner_.joinable()) {
      spinner_.join();
    }
    rclcpp::shutdown();
  }

private:
  physics::ModelPtr model_;
  event::ConnectionPtr update_connection_;
  rclcpp::Node::SharedPtr node_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
  std::shared_ptr<rclcpp::executors::SingleThreadedExecutor> executor_;
  std::thread spinner_;
  geometry_msgs::msg::Twist last_cmd_{};
};

GZ_REGISTER_MODEL_PLUGIN(WanderbotMotionPlugin)
}  // namespace gazebo
