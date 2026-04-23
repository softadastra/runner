/**
 *
 *  @file RunnerService.hpp
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
#ifndef SOFTADASTRA_RUNNER_CORE_RUNNERSERVICE_HPP
#define SOFTADASTRA_RUNNER_CORE_RUNNERSERVICE_HPP

#include <memory>

#include <softadastra/runner/core/CommandRequest.hpp>
#include <softadastra/runner/core/CommandResult.hpp>

namespace softadastra::runner::infrastructure
{
  class VixProcessExecutor;
}

namespace softadastra::runner::core
{
  /**
   * @class RunnerService
   * @brief Core service responsible for executing commands.
   *
   * This class orchestrates:
   * - validation of command requests
   * - delegation to an execution backend
   * - returning a normalized command result
   *
   * Design goals:
   * - isolate business logic from infrastructure
   * - provide a simple API for command execution
   * - remain independent from Vix or any specific backend
   */
  class RunnerService
  {
  public:
    /**
     * @brief Construct a runner service with a process executor.
     *
     * @param executor Execution backend implementation.
     */
    explicit RunnerService(std::shared_ptr<infrastructure::VixProcessExecutor> executor);

    /**
     * @brief Execute a command request.
     *
     * Expected behavior:
     * - validates the request
     * - delegates execution to the backend
     * - returns a command result
     *
     * @param request Command to execute.
     * @return CommandResult containing execution output.
     */
    [[nodiscard]] CommandResult run(const CommandRequest &request) const;

  private:
    std::shared_ptr<infrastructure::VixProcessExecutor> executor_{};
  };

} // namespace softadastra::runner::core

#endif // SOFTADASTRA_RUNNER_CORE_RUNNERSERVICE_HPP
