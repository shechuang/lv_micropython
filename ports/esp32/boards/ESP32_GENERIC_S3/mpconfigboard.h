#ifndef MICROPY_HW_BOARD_NAME
// 改个名字，方便你在 REPL 界面一眼看出刷对固件了
#define MICROPY_HW_BOARD_NAME               "ESP32S3-N16R8-LVGL"
#endif
#define MICROPY_HW_MCU_NAME                 "ESP32S3"

// 启用 UART REPL
#define MICROPY_HW_ENABLE_UART_REPL         (1)

// 你的 I2C 引脚定义（如果不需要改可以保持原样）
#define MICROPY_HW_I2C0_SCL                 (9)
#define MICROPY_HW_I2C0_SDA                 (8)

// --- 针对 8MB PSRAM 的关键增加内容 ---

// 1. 启用外部 SPIRAM 支持
#define MICROPY_ESP32_EXT_SPIRAM            (1)

// 2. 增加 Python 堆栈大小，防止运行大型软件（如 LVGL）时溢出
#define MICROPY_STACK_CHECK                 (1)

// 3. 这里的内存阈值设置。当内存占用达到这个比例时，自动触发垃圾回收
// 针对 8MB PSRAM，我们调高一点点，减少 GC 频率
#define MICROPY_GC_ALLOC_THRESHOLD          (128 * 1024)

// 4. 允许 MicroPython 搜索更多的路径（软件工程大了之后文件会很多）
#define MICROPY_ALLOC_PATH_MAX              (256)
