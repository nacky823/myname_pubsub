cmake_minimum_required(VERSION 3.8)
project(myname_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(include)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Create executable
add_executable(name_pubsub_exe src/main.cpp)
ament_target_dependencies(name_pubsub_exe rclcpp std_msgs)

# install main
install(TARGETS
  name_pubsub_exe
  DESTINATION lib/${PROJECT_NAME}
)

# install launch
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# install config
install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
