# Copyright 2023 nacky823
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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