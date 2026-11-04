## Building and Loading a Driver

### 1. Install Kernel Headers

Before building any kernel module, install the Raspberry Pi kernel headers.

```bash
sudo apt update
sudo apt install raspberrypi-kernel-headers
sudo apt upgrade
```

Verify that the `build` directory exists:

```bash
ls -l /lib/modules/$(uname -r)/build
```

Expected output:

```text
/lib/modules/<kernel-version>/build -> /usr/src/linux-headers-<kernel-version>
```

---

### 2. Project Structure

The driver project should contain at least:

```text
── 02-char-driver/
    ├── char_driver.c
    └── Makefile
```

---

### 3. Build the Driver

Navigate to the driver directory and run:

```bash
make all
```

After a successful build, a kernel module (`.ko`) file will be generated:

```text
char_driver.ko
```

The `.ko` file is the loadable Linux Kernel Module.

---

### 4. Load the Driver

Insert the module into the running kernel:

```bash
sudo insmod char_driver.ko
```

Verify that the module has been loaded:

```bash
lsmod | grep char_driver
```

---

### 5. Check Kernel Messages

Display recent kernel log messages:

```bash
dmesg | tail -n 20
```

---

### 6. Remove the Driver

Unload the module from the kernel:

```bash
sudo rmmod char_driver
```

Verify removal:

```bash
lsmod | grep char_driver
```

No output indicates that the module was successfully unloaded.

---

### Useful Commands

See /proc/devices to find out how major numbers are assigned on a running Linux instance.

```bash
uname -r                      # Current Kernel Version

lsmod                         # List Loaded Modules

modinfo char_driver.ko       # Module Information

dmesg | tail -n 20            # Recent Kernel Logs

sudo insmod char_driver.ko   # Load Module

sudo rmmod char_driver       # Unload Module
