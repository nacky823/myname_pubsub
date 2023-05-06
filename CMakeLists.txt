cmake_minimum_required(VERSION 3.8)
project(myname_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(std_msgs REQUIRED)

# Can be omitted "find dependencies" in ament_auto
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

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

include_directories(include)

# Create executable
ament_auto_add_executable(name_pubsub src/main.cpp)

# Add Backward ROS
add_backward(name_pubsub)

# Install directories (Cannot be omitted in ament_auto)
install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

# ament_package()
# Install executables (Can be omitted in ament_auto)
ament_auto_package()
