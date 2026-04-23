/**
 *
 *  @file RunnerApp.hpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/softadastra/runner
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Softadastra Runner
 *
 */
#ifndef SOFTADASTRA_RUNNER_APP_RUNNERAPP_HPP
#define SOFTADASTRA_RUNNER_APP_RUNNERAPP_HPP

#include <memory>

#include <softadastra/runner/cli/Console.hpp>
#include <softadastra/runner/cli/InputParser.hpp>
#include <softadastra/runner/cli/Prompt.hpp>
#include <softadastra/runner/core/RunnerService.hpp>
#include <softadastra/runner/infrastructure/VixProcessExecutor.hpp>

namespace softadastra::runner::app
{
  /**
   * @class RunnerApp
   * @brief Main application orchestrator.
   *
   * This class is responsible for:
   * - running the main loop
   * - coordinating CLI, parsing, and execution
   * - handling application lifecycle
   *
   * Design goals:
   * - keep main() minimal
   * - centralize orchestration logic
   * - remain simple and extensible
   */
  class RunnerApp
  {
  public:
    /**
     * @brief Construct the application with default components.
     */
    RunnerApp();

    /**
     * @brief Run the application.
     *
     * Expected behavior:
     * - display prompt
     * - read user input
     * - parse command
     * - execute command
     * - display result
     * - repeat until exit
     *
     * @return Exit code.
     */
    int run();

  private:
    /**
     * @brief Handle a single input line.
     *
     * @param input Raw user input.
     * @return false if the application should stop.
     */
    bool handle_input(const std::string &input);

  private:
    cli::Console console_{};
    cli::Prompt prompt_{};
    cli::InputParser parser_{};

    std::shared_ptr<infrastructure::VixProcessExecutor> executor_{};
    core::RunnerService service_;
  };

} // namespace softadastra::runner::app

#endif // SOFTADASTRA_RUNNER_APP_RUNNERAPP_HPP
