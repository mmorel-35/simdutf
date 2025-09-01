# simdutf Bazel Module

This is a Bazel module for the [simdutf](https://github.com/simdutf/simdutf) library - a fast Unicode validation, transcoding and processing library.

## Usage

Add the following to your `MODULE.bazel` file:

```starlark
bazel_dep(name = "simdutf", version = "7.4.0")
```

## Targets

### Simple Target (Recommended for most use cases)

```starlark
cc_library(
    name = "my_library",
    srcs = ["my_library.cpp"],
    deps = ["@simdutf//:simdutf"],
)
```

This provides the standard simdutf library compiled from sources. This is equivalent to what envoy expects:

```starlark
cc_library(
    name = "simdutf",
    srcs = ["simdutf.cpp"],
    hdrs = ["simdutf.h"],
)
```

### Full Target (For advanced use cases)

```starlark
cc_library(
    name = "my_library",
    srcs = ["my_library.cpp"],
    deps = ["@simdutf//:simdutf_full"],
)
```

This target includes additional compiler optimizations and warnings that match the CMake build.

### Headers Only

```starlark
cc_library(
    name = "my_library",
    srcs = ["my_library.cpp"],
    deps = ["@simdutf//:simdutf_headers"],
)
```

This provides just the headers if you want to include your own implementation.

## Example

See `examples/demo.cpp` for a simple usage example.

## Features

- UTF-8, UTF-16, UTF-32 validation
- Fast transcoding between Unicode encodings
- SIMD-optimized implementations for various architectures (x86-64, ARM64, etc.)
- Header-only option available
- Compatible with C++11 and later

## Compatibility

This Bazel module is compatible with:
- Bazel 6.0+ 
- C++11 and later
- Linux, macOS, Windows
- x86-64, ARM64, and other architectures

## License

simdutf is dual-licensed under Apache 2.0 and MIT licenses.