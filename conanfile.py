from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeToolchain, CMakeDeps

class Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def requirements(self):
        self.requires("catch2/3.5.2")
        self.requires("libcurl/8.6.0")
        self.requires("poco/1.13.3")
        self.requires("oatpp/1.3.0")


    def layout(self):
        # Cmake default build layout
        cmake_layout(self)