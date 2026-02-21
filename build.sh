conan remove mystore -c
conan remove clock -c
conan remove ui -c
conan remove app -c
conan create clock/ -pr:b x86_64_debian -pr:h x86_64_debian
conan create ui/ -pr:b x86_64_debian -pr:h x86_64_debian
conan create app/ -pr:b x86_64_debian -pr:h x86_64_debian