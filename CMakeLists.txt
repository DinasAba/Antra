include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0 # Выберите нужную версию
)

FetchContent_MakeAvailable(googletest)

# Добавьте вашу цель тестирования и файлы тестов
add_executable(MyTests
        testai.cpp
        main.cpp
        funkcijos.cpp
)

# Свяжите цель тестирования с библиотекой Google Test
target_link_libraries(MyTests
        gtest_main # Используйте gtest_main, если вы хотите, чтобы Google Test создавал свои собственные main-функции
)

# Добавьте зависимости для ваших тестов
add_dependencies(MyTests Pirmas)

# Подключите директорию с заголовочными файлами вашего проекта
target_include_directories(MyTests PRIVATE ${CMAKE_SOURCE_DIR})
