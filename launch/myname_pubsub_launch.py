from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    talker_comp = Node(
        package="myname_pubsub",
        executable="talker",
        name="talker_launch",
        output="screen",
        emulate_tty=True,
        parameters=[
            {"pub_rate": 1.5}
        ]
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