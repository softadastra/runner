/**
 *
 *  @file VixProcessExecutor.hpp
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
#ifndef SOFTADASTRA_RUNNER_INFRASTRUCTURE_VIXPROCESSEXECUTOR_HPP
#define SOFTADASTRA_RUNNER_INFRASTRUCTURE_VIXPROCESSEXECUTOR_HPP

#include <softadastra/runner/core/CommandRequest.hpp>
#include <softadastra/runner/core/CommandResult.hpp>

namespace softadastra::runner::infrastructure
{
  /**
   * @class VixProcessExecutor
   * @brief Executes commands using Vix process module.
   *
   * This class is responsible for:
   * - translating CommandRequest into vix::process::Command
   * - executing the command using Vix
   * - converting the result into CommandResult
   *
   * Design goals:
   * - isolate Vix dependency from core logic
   * - provide a simple execution interface
   * - allow future replacement of execution backend
   */
  class VixProcessExecutor
  {
  public:
    /**
     * @brief Execute a command request using Vix.
     *
     * Expected behavior:
     * - builds a Vix command
     * - configures stdout/stderr capture
     * - runs the command
     * - returns a normalized result
     *
     * @param request Command to execute.
     * @return CommandResult containing execution output.
     */
    [[nodiscard]] core::CommandResult execute(const core::CommandRequest &request) const;
  };

} // namespace softadastra::runner::infrastructure

#endif // SOFTADASTRA_RUNNER_INFRASTRUCTURE_VIXPROCESSEXECUTOR_HPP
