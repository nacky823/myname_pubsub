from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    ld = LaunchDescription()

    params_file = os.path.join(
        get_package_share_directory("myname_pubsub"),
        "config",
        "params_myname.param.yaml"
    )

    name = Node(
        package="myname_pubsub",
        executable="name_pubsub_exe",
        name="myname_pubsub",
        output="screen",
        emulate_tty=True,
        parameters=[params_file]
    )

    ld.add_action(name)

    return ld