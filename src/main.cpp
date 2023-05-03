#include "myname_pubsub/talker_comp.hpp"
#include "myname_pubsub/listener_comp.hpp"
#include "rclcpp/rclcpp.hpp"
#include <memory>

int main(int argc, char* argv[])
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    rclcpp::init(argc, argv);

    rclcpp::executors::SingleThreadedExecutor exec;
    rclcpp::NodeOptions options;

    auto talker = std::make_shared<myname_pubsub::TalkerComp>(options);
    exec.add_node(talker);
    auto listener = std::make_shared<myname_pubsub::ListenerComp>(options);
    exec.add_node(listener);

    exec.spin();

    rclcpp::shutdown();

    return 0;
}