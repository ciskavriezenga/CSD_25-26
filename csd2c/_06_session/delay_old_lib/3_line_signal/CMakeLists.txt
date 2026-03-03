project(line_signal VERSION 0.0.1)
juce_add_console_app(line_signal PRODUCT_NAME "delay")
target_sources(line_signal PRIVATE main.cpp signal.cpp line.cpp)
target_compile_definitions(line_signal PRIVATE SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(line_signal PRIVATE
        audio
        PUBLIC
)

target_compile_features(line_signal PRIVATE cxx_std_20)