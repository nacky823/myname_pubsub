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

    talker_comp = Node(
        package="myname_pubsub",
        executable="talker",
        name="talker_launch",
        output="screen",
        emulate_tty=True,
        parameters=[params_file]
    )

    listener_comp = Node(
        package="myname_pubsub",
        executable="listener",
        name="listener_launch",
        output="screen",
        emulate_tty=True,
    )

    ld.add_action(talker_comp)
    ld.add_action(listener_comp)

    return ld