# PAT Team 项目

这是一个包含多个 PAT (Programming Ability Test) 题目解决方案的 Rust 项目。

## 项目结构

```
Team/
├── Cargo.toml       # Rust 项目配置文件
├── README.md        # 项目说明文档
├── l1_074.rs        # 题目解决方案
├── l1_077.rs        # 题目解决方案
├── l1_081.rs        # 题目解决方案
├── l1_082.rs        # 题目解决方案
├── l1_084.rs        # 题目解决方案
├── l1_091.rs        # 题目解决方案
├── l1_092.rs        # 题目解决方案
├── l1_093.rs        # 题目解决方案
├── l1_097.rs        # 题目解决方案
└── l1_098.rs        # 题目解决方案
```

## 如何使用

### 1. 格式化代码

使用 `cargo fmt` 命令来格式化所有 Rust 文件，保持代码风格一致：

```bash
# 在 Team 目录下运行
cargo fmt
```

### 2. 代码质量检查

使用 `cargo clippy` 命令来检查代码质量，发现潜在问题：

```bash
# 在 Team 目录下运行
cargo clippy
```

### 3. 运行单个文件

由于这些是独立的 Rust 文件，你可以使用 `rustc` 编译并运行它们，或者使用 `cargo run --bin` 命令。

#### 方法一：使用 rustc 直接编译运行

```bash
# 编译单个文件
rustc l1_074.rs -o l1_074

# 运行编译后的可执行文件
./l1_074
```

#### 方法二：使用 cargo run（推荐）

项目已经在 Cargo.toml 中配置了所有文件的二进制目标，你可以直接使用以下命令运行任何文件：

```bash
# 运行 l1_074.rs
cargo run --bin l1_074

# 运行 l1_077.rs
cargo run --bin l1_077

# 运行 l1_081.rs
cargo run --bin l1_081

# 运行 l1_082.rs
cargo run --bin l1_082

# 运行 l1_084.rs
cargo run --bin l1_084

# 运行 l1_091.rs
cargo run --bin l1_091

# 运行 l1_092.rs
cargo run --bin l1_092

# 运行 l1_093.rs
cargo run --bin l1_093

# 运行 l1_097.rs
cargo run --bin l1_097

# 运行 l1_098.rs
cargo run --bin l1_098
```

## 依赖安装

如果你还没有安装 Rust 工具链，请按照以下步骤安装：

1. 访问 [https://www.rust-lang.org/tools/install](https://www.rust-lang.org/tools/install)
2. 按照页面上的说明下载并安装 Rust
3. 验证安装是否成功：

```bash
rustc --version
cargo --version
```

## 注意事项

- 每个 `.rs` 文件都是一个独立的程序，包含了完整的 `main` 函数
- 你可以根据需要为每个文件添加对应的二进制目标到 Cargo.toml 中
- 使用 `cargo fmt` 和 `cargo clippy` 可以帮助你保持代码质量和风格一致性
