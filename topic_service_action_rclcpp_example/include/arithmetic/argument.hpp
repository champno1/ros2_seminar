// Copyright 2021 OROCA
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ARITHMETIC__ARGUMENT_HPP_
#define ARITHMETIC__ARGUMENT_HPP_

#include <chrono> //time manipulation library
#include <memory> //dynamic memory manipulation library
#include <string>
#include <utility>

#include "rclcpp/rclcpp.hpp"

#include "msg_srv_action_interface_example/msg/arithmetic_argument.hpp"


class Argument : public rclcpp::Node  //Argument class is a subclass of Node class
{
public:
  using ArithmeticArgument = msg_srv_action_interface_example::msg::ArithmeticArgument;

  explicit Argument(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions());  //Constructor. get node option input(context, arguments, intra-process comm, parameter, allocator etc.).
  virtual ~Argument();

private:
  void publish_random_arithmetic_arguments();
  void update_parameter();

  float min_random_num_;  //to limit sampling range of topic data
  float max_random_num_;  //to limit sampling range of topic data

  rclcpp::Publisher<ArithmeticArgument>::SharedPtr arithmetic_argument_publisher_;  //Publisher member variable with smartpointer type
  rclcpp::TimerBase::SharedPtr timer_;  //Timer member variable with smartpointer type
  rclcpp::Subscription<rcl_interfaces::msg::ParameterEvent>::SharedPtr parameter_event_sub_;  //subscriber to get parameter event
  rclcpp::AsyncParametersClient::SharedPtr parameters_client_;  //parament client
};
#endif  // ARITHMETIC__ARGUMENT_HPP_
