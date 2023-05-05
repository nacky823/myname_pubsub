from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    name = Node(
        package="myname_pubsub",
        executable="name_pubsub_exe",
        name="myname_pubsub",
        output="screen",
        emulate_tty=True,
        parameters=[
            {"pub_rate": 1.5}
        ]
    )

    ld.add_action(name)

    return ld