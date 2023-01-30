add_rules("mode.debug", "mode.release")

target("trabalho-grafos")
    set_kind("binary")
    add_files("src/*.cpp")
