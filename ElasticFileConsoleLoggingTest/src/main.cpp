#include "Logger.h"
#include "iostream"

int main() {
    Logger::readConfiguration(); // PRIORITY = INFO

    std::cout << "PRIORITY -> INFO \n";

    Logger::Info("Should display: %s", "INFO LOG");
    Logger::Debug("Should NOT display: %s", "DEBUG LOG");
    Logger::Trace("Should NOT display: %s", "TRACE LOG");
    Logger::Warn("Should display: %s", "WARN LOG");
    Logger::Error("Should display: %s", "ERROR LOG");
    Logger::Critical("Should display: %s", "CRITICAL LOG");

    std::cout << "\n" << "PRIORITY -> ERROR \n";

    Logger::setPriority(LogPriority::ErrorPriority);
    Logger::Info("Should NOT display: %s", "INFO LOG");
    Logger::Debug("Should NOT display: %s", "DEBUG LOG");
    Logger::Trace("Should NOT display: %s", "TRACE LOG");
    Logger::Warn("Should NOT display: %s", "WARN LOG");
    Logger::Error("Should display: %s", "ERROR LOG");
    Logger::Critical("Should display: %s", "CRITICAL LOG");


    std::cout << "\n" << "PRIORITY -> TRACE \n";

    Logger::setPriority(LogPriority::TracePriority);
    Logger::Info("Should display: %s", "INFO LOG");
    Logger::Debug("Should display: %s", "DEBUG LOG");
    Logger::Trace("Should display: %s", "TRACE LOG");
    Logger::Warn("Should display: %s", "WARN LOG");
    Logger::Error("Should display: %s", "ERROR LOG");
    Logger::Critical("Should display: %s", "CRITICAL LOG");

    return 0;
}
