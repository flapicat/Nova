#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Nova
{
	class  Log
	{
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//CORE LOG MACROS
#define NV_CORE_TRACE(...)     ::Nova::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define NV_CORE_INFO(...)      ::Nova::Log::GetCoreLogger()->info(__VA_ARGS__);
#define NV_CORE_WARN(...)      ::Nova::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define NV_CORE_ERROR(...)     ::Nova::Log::GetCoreLogger()->error(__VA_ARGS__);
#define NV_CORE_FATAL(...)     ::Nova::Log::GetCoreLogger()->fatal(__VA_ARGS__);

//CLIENT LOG MACROS
#define NV_TRACE(...)     ::Nova::Log::GetClientLogger()->trace(__VA_ARGS__);
#define NV_INFO(...)      ::Nova::Log::GetClientLogger()->info(__VA_ARGS__);
#define NV_WARN(...)      ::Nova::Log::GetClientLogger()->warn(__VA_ARGS__);
#define NV_ERROR(...)     ::Nova::Log::GetClientLogger()->error(__VA_ARGS__);
#define NV_FATAL(...)     ::Nova::Log::GetClientLogger()->fatal(__VA_ARGS__);