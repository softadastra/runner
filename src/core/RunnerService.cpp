/**
 *
 *  @file RunnerService.cpp
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

#include <softadastra/runner/core/RunnerService.hpp>
#include <softadastra/runner/infrastructure/VixProcessExecutor.hpp>

namespace softadastra::runner::core
{

  RunnerService::RunnerService(std::shared_ptr<infrastructure::VixProcessExecutor> executor)
      : executor_(std::move(executor))
  {
  }

  CommandResult RunnerService::run(const CommandRequest &request) const
  {
    if (!request.valid())
    {
      CommandResult result;
      result.exit_code = 1;
      result.stderr_text = "invalid command: program is empty";
      return result;
    }

    if (!executor_)
    {
      CommandResult result;
      result.exit_code = 1;
      result.stderr_text = "internal error: executor not configured";
      return result;
    }

    return executor_->execute(request);
  }

} // namespace softadastra::runner::core
