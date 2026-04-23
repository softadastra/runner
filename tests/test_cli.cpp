/**
 *
 *  @file test_cli.cpp
 *  @author Gaspard Kirira
 *
 *  Softadastra Runner - CLI Test
 *
 */

#include <iostream>

#include <softadastra/runner/cli/InputParser.hpp>
#include <softadastra/runner/cli/Console.hpp>
#include <softadastra/runner/core/CommandResult.hpp>

int main()
{
  using namespace softadastra::runner;

  cli::InputParser parser;
  cli::Console console;

  std::string input = "echo hello world";

  auto request = parser.parse(input);

  console.write("Program: " + request.program + "\n");

  console.write("Arguments:\n");
  for (const auto &arg : request.arguments)
  {
    console.write("  - " + arg + "\n");
  }

  core::CommandResult result;
  result.exit_code = 0;
  result.stdout_text = "hello world\n";
  result.stderr_text = "";

  console.write("\n--- Display Result ---\n");
  console.display_result(result);

  return 0;
}
