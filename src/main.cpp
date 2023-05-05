#include "myname_pubsub/main.hpp"
#include <memory>
#include <chrono>
#include <functional>
#include <string>

using std::placeholders::_1;
using namespace std::chrono_literals;

namespace myname_pubsub
{

ListenerComp::ListenerComp(const rclcpp::NodeOptions &options)
: Node("listener", options)
{
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "name_topic", 10, std::bind(&ListenerComp::topic_callback, this, _1)
    );
}

void ListenerComp::topic_callback(const std_msgs::msg::String &msg) const
{
    RCLCPP_INFO(this->get_logger(), "Subscibed : '%s'", msg.data.c_str());
}

TalkerComp::TalkerComp(const rclcpp::NodeOptions & options)
: Node("talker", options)
, count_(0)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("name_topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&TalkerComp::timer_callback, this)
    );
}

void myname_pubsub::TalkerComp::timer_callback()
{
    auto message = std_msgs::msg::String(); // declare message

    /* messabe data */
    if(count_ != 9)
    {
        message.data = "nacky, count = " + std::to_string(count_++);
    }
    else
    {
        message.data = "Mr.Ikebe, count = " + std::to_string(count_);
        count_ = 0;
    }

    /* publish message */
    //RCLCPP_INFO(this->get_logger(), "Publishing : '%s'", message.data.c_str());

    publisher_->publish(message); // publish
}

} // namespace myname_pubsub

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