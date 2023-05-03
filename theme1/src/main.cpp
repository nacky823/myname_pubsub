#include "theme1/talker_comp.hpp"
#include "rclcpp/rclcpp.hpp"
#include <memory>

int main(int argc, char argv[])
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    rclcpp::init(argc, argv);

    rclcpp::executors::SingleThreadedExecutor exec;
    rclcpp::NodeOptions options;

    auto talker = std::make_shared<theme::TalkerComp>(options);
    exec.add_node(talker);

    exec.spin();

    rclcpp::shutdown();

    return 0;
}