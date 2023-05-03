from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="myname_pubsub",
            executable="name_pubsub",
            name="myname_pubsub",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"pub_rate": 1.5}
            ]
        )
    ])