/**
 *
 *  @file test_basic.cpp
 *  @author Gaspard Kirira
 *
 *  Softadastra Runner - Basic Test
 *
 */

#include <iostream>

#include <softadastra/runner/core/CommandRequest.hpp>
#include <softadastra/runner/core/RunnerService.hpp>
#include <softadastra/runner/infrastructure/VixProcessExecutor.hpp>

int main()
{
  using namespace softadastra::runner;

  auto executor = std::make_shared<infrastructure::VixProcessExecutor>();
  core::RunnerService service(executor);

  core::CommandRequest request;
  request.program = "echo";
  request.arguments = {"hello", "from", "runner"};

  auto result = service.run(request);

  std::cout << "exit code: " << result.exit_code << '\n';
  std::cout << "stdout: " << result.stdout_text << '\n';
  std::cout << "stderr: " << result.stderr_text << '\n';

  return result.success() ? 0 : 1;
}
