
# Every

  Execute a command every N seconds. Aka basically
  cron without the weird-ass syntax.

## Installation

```
$ git clone git://github.com/visionmedia/every.git
$ git submodule update --init
$ make install
```

## Usage

```

Usage: every <interval> <cmd ...>

Options:

  -V, --version                 output program version
  -h, --help                    output help information

```

## Examples

```
$ every 5s echo hey
$ every 10m check mail
$ every 6h ./populate-redis
```

## Links

  Need to make sure `every(1)` stays running? Maybe
  check out [mon(1)](https://github.com/visionmedia/mon).

# License

  MIT
