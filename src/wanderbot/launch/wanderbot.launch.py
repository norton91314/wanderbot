from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node
from pathlib import Path


def generate_launch_description():
    pkg_share = get_package_share_directory('wanderbot')
    world_file = str(Path(pkg_share).parent / 'gazeboworlds' / 'obstacle_box.sdf')

    return LaunchDescription([
        ExecuteProcess(
            cmd=['gazebo', '--verbose', world_file],
            output='screen'
        ),
        Node(
            package='wanderbot',
            executable='wanderbot_node',
            output='screen'
        )
    ])
