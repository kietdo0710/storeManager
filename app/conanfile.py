import os
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout, CMakeDeps
from conan.tools.files import copy

class AppRecipe(ConanFile):
    name = "app"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "*.cpp", "*.hpp"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def requirements(self):
        self.requires("clock/1.0")
        self.requires("ui/1.0")

    def generate(self):
        for dep in self.dependencies.values():
            copy(self, "*", dep.cpp_info.libdirs[0], os.path.join(self.source_folder, dep.ref.name))
            copy(self, "*", dep.cpp_info.includedirs[0], os.path.join(self.source_folder, dep.ref.name))
        tc = CMakeToolchain(self)
        tc.generate()    
        deps = CMakeDeps(self)
        deps.generate()        

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
