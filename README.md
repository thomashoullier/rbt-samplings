# RobinTrace samplings

![status](https://raw.githubusercontent.com/thomashoullier/badges/master/status-maintained.svg)
![stage](https://raw.githubusercontent.com/thomashoullier/badges/master/stage-alpha.svg)

[![Build Status](https://drone.git-or-miss.com/api/badges/thomashoullier/rbt-samplings/status.svg)](https://drone.git-or-miss.com/thomashoullier/rbt-samplings)
[![codecov](https://codecov.io/gh/thomashoullier/rbt-samplings/branch/master/graph/badge.svg?token=JGKGCKX1HP)](https://codecov.io/gh/thomashoullier/rbt-samplings)

`rbt_samplings` is a utility library defining point sampling schemes over
apertures for RobinTrace.

## Documentation
See the [Doxygen
pages](https://thomashoullier.github.io/rbt-samplings/index.html).

## Building
We use cmake. Switch to a `build/` directory and run the following:

```shell
cmake -Drbt-samplings-test=ON
      -Drbt-samplings-coverage=ON
      -Drbt-samplings-example=ON
      ..
```

The targets are the following:
* `rbt-samplings-example`: An example file.
* `rbt-samplings-test`: Test suite.
* The test coverage report.

## Dependencies
We use the following libraries:
* [RobinTrace](https://github.com/thomashoullier/robintrace)
* [qhull](https://github.com/qhull/qhull)

In addition, only for tests:
* [Catch2](https://github.com/catchorg/Catch2)
* `boost/iostreams`
