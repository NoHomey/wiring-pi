# System Error


# Table of `syscall`s from which `WiringPi` may `return` a possible `errno`

| `errno`        | `open` | `ioctl` | `pthread_create` | `read` | `fork` | `execl` |
| -------------- | ------ | ------- | ---------------- | ------ | ------ | ------- |
| `EACCESS`      | ✓      |        |                   |        |        | ✓      |
| `EDQUOT`       | ✓      |        |                   |        |        |        |
| `EEXIST`       | ✓      |        |                   |        |        |        |
| `EFAULT`       | ✓      | ✓      |                   | ✓     |        | ✓      |
| `EFBIG`        | ✓      |        |                   |        |        |        |
| `EINTR`        | ✓      |        |                   | ✓      |        |        |
| `EINVAL`       | ✓      | ✓      |  ✓               | ✓      |        | ✓      |
| `EISDIR`       | ✓      |        |                   | ✓      |        | ✓      |
| `ELOOP`        | ✓      |        |                   |        |        | ✓      |
| `EMFILE`       | ✓      |        |                   |        |        | ✓      |
| `ENAMETOOLONG` | ✓      |        |                   |        |        | ✓      |
| `ENFILE`       | ✓      |        |                   |        |        | ✓      |
| `ENODEV`       | ✓      |        |                   |        |        |        |
| `ENOENT`       | ✓      |        |                   |        |        | ✓      |
| `ENOMEM`       | ✓      |        |                   |        | ✓      | ✓      |
| `ENOSPC`       | ✓      |        |                   |        |        |         |
| `ENOTDIR`      | ✓      |        |                   |        |        | ✓      |
| `ENXIO`        | ✓      |        |                   |        |        |        |
| `EOPNOTSUPP`   | ✓      |        |                   |        |        |        |
| `EOVERFLOW`    | ✓      |        |                   |        |        |        |
| `EPERM`        | ✓      |        | ✓                 |        |        | ✓     |
| `EROFS`        | ✓      |        |                   |        |        |        |
| `ETXTBSY`      | ✓      |        |                   |        |        | ✓      |
| `ENOTTY`       |        | ✓      |                   |        |        |        |
| `EBADF`        | ✓      | ✓      |                   | ✓     |        |        |
| `EAGAIN`       | ✓      |        | ✓                 | ✓     | ✓      |        |
| `ENOSYS`       |        |        |                   |        | ✓      |        |
| `EIO`          |        |        |                   | ✓      |        | ✓       |
| `ELIBBAD`      |        |        |                   |        |        | ✓       |
| `ENOEXEC`      |        |        |                   |        |        | ✓       |
| `E2BIG`        |        |        |                   |        |        | ✓       |

# Table of `fuction`s from which `WiringPi` possibly `returns` `errno` after makin a `syscall`, and their categorisation (category)

| `function`                   | `open` | `ioctl` | `pthread_create` | `read` | `fork` | `execl` | (category) |
| ---------------------------- | ------ | ------- | ---------------- | ------ | ------ | ------- | ---------- | 
| `wiringPiISR`                | ✓      |         |                  |        | ✓     | ✓       |     (1)    |
| `wiringPiI2CSetup`           | ✓      | ✓       |                  |        |        |         |     (2)   |
| `wiringPiI2CSetupInterfaces` | ✓      | ✓       |                  |        |        |         |     (2)   |
| `wirngPiI2CWriteReg16`       |        | ✓       |                  |        |        |         |     (3)   |
| `wirngPiI2CWriteReg8`        |        | ✓       |                  |        |        |         |     (3)   |
| `wirngPiI2CReadReg16`        |        | ✓       |                  |        |        |         |     (3)   |
| `wirngPiI2CReadReg8`         |        | ✓       |                  |        |        |         |     (3)   |
| `wirngPiI2CWrite`            |        | ✓       |                  |        |        |         |     (3)   |
| `wirngPiI2CRead`             |        | ✓       |                  |        |        |         |    (3)    |
| `wiringPiSPISetup`           | ✓      | ✓       |                  |        |        |         |    (2)   |
| `wiringPiSPISetupMode`       | ✓      | ✓       |                  |        |        |         |    (2)   |
| `wiringPiSPIDataRW`          |        | ✓       |                  |        |        |         |    (3)   |
| `serialOpen`                 | ✓      |         |                  |        |        |         |    (4)   |
| `serialDataAvail`            |        | ✓       |                  |        |        |         |    (3)   |
| `serialGetChar`              |        |         |                   | ✓     |        |         |    (5)   |
| `softPWMCreate`              |        |         | ✓                |        |        |         |    (6)   |
| `softServoSetup`             |        |         | ✓                |        |        |         |    (6)   |
| `softToneCreate`             |        |         | ✓                |        |        |         |    (6)   |

# Table of `syscall` decucted based on `errno` and `WiringPi` `function` (category), and the default deducted `syscall`

| `errno`        |        (1)       |        (2)       |        (3)       |        (4)       |        (5)       |        (6)       | default          |
| -------------- | ---------------- | ---------------- | ---------------- | ---------------- | ---------------- | ---------------- | ---------------- |
| `EACCESS`      | `execl`          | `open`           | default          | `open`           | default          | default          | `open`           |
| `EDQUOT`       | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EEXIST`       | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EFAULT`       | `open`           | `ioctl`          | `ioctl`          | `open`           | `read`           | default          | `ioctl`          |
| `EFBIG`        | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EINTR`        | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EINVAL`       | `open`           | `ioctl`          | `ioctl`          | `open`           | `read`           | `pthread_create` | `ioctl`          |
| `EISDIR`       | `execl`          | `open`           | default          | `open`           | `read`           | default          | `open`           |
| `ELOOP`        | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EMFILE`       | `execl`          | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENAMETOOLONG` | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENFILE`       | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENODEV`       | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENOENT`       | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENOMEM`       | `fork`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENOSPC`       | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENOTDIR`      | `execl`          | `open`           | default          | `open`           | default          | default          | `open`           |
| `ENXIO`        | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EOPNOTSUPP`   | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EOVERFLOW`    | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `EPERM`        | `execl`          | `open`           | default          | `open`           | default          | `pthread_create` | `open`           |
| `EROFS`        | `open`           | `open`           | default          | `open`           | default          | default          | `open`           |
| `ETXTBSY`      | `execl`          | `open`           | default          | `open`           | default          | default          | `execl`          |
| `ENOTTY`       | default          | `ioctl`          | `ioctl`          | default          | `read`           | default          | `ioctl`          |
| `EBADF`        | default          | `ioctl`          | `ioctl`          | default          | `read`           | default          | `ioctl`          |
| `EAGAIN`       | `fork`           | `open`           | default          | `open`           | default          | `pthread_create` | `open`           |
| `ENOSYS`       | `fork`           | default          | default          | default          | default          | default          | `fork`           |
| `EIO`          | `execl`          | default          | default          | default          | `read`           | default          | `read`           |
| `ELIBBAD`      | `execl`          | default          | default          | default          | default          | default          | `execl`          |
| `ENOEXEC`      | `execl`          | default          | default          | default          | default          | default          | `execl`          |
| `E2BIG`        | `execl`          | default          | default          | default          | default          | default          | `execl`          |
| *              | default          | default          | default          | default          | default          | default          | `""`             |