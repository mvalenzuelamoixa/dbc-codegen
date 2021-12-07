# CAN DBC code generator for Rust

Generates Rust messages from a `dbc` file.

⚠️ This is experimental - use with caution. ⚠️

## Installation

Install published version using [cargo](https://doc.rust-lang.org/cargo/getting-started/installation.html):

```bash
cargo install dbc-codegen-cli
```
Install latest version from the git repository:

```bash
cargo install dbc-codegen-cli --git https://github.com/technocreatives/dbc-codegen --branch main
```

## Using dbc-codegen

Generate `messages.rs` from `example.dbc` using the CLI:

```bash
dbc-codegen testing/dbc-examples/example.dbc dir/where/messages_rs/file/is/written
```

Or put something like this into your `build.rs` file:

```rust
fn main() {
    let dbc_path = "../dbc-examples/example.dbc";
    let dbc_file = std::fs::read(dbc_path).unwrap();
    println!("cargo:rerun-if-changed={}", dbc_path);

    let mut out = std::io::BufWriter::new(std::fs::File::create("src/messages.rs").unwrap());
    dbc_codegen::codegen("example.dbc", &dbc_file, &mut out, true).unwrap();
}
```

## Using generated Rust code

dbc-codegen generates a Rust file that is expected to be in a cargo project.
Here is an example [`testing/can-messages/Cargo.toml`](testing/can-messages/Cargo.toml) which defines dependencies and features that are used in generated message file.

### Project setup

For this to work you need to add following dependencies to `Cargo.toml`:

```toml
bitvec = { version = "0.21", default-features = false }
arbitrary = { version = "1.0", optional = true } # Enable with `arb` feature
num-traits = { version = "0.2.14", optional = true }
```

To use the code, add `mod messages` to your `lib.rs` (or `main.rs`).
You will most likely want to interact with the generated `Messages` enum, and call `Messages::from_can_message(id, &payload)`.

Note: The generated code contains a lot of documentation.
Give it a try:
```bash
cargo doc --open
```

### Feature flags

The following (optional) features can be specified:

- `debug`: enables `#[derive(Debug)` for messages
- `range_checked`: adds range checks in setters
- `arb`: enables implementation of [`Arbitrary`] trait.
  Also requires you to add `arbitrary` crate (version 1.x) as a dependency of the feature, using `arb = ["arbitrary"]`.
  [`Arbitrary`]: https://docs.rs/arbitrary/1.0.0/arbitrary/trait.Arbitrary.html
- `std`: Implements `std::error::Error` for `CanError`. This makes it easy to use `anyhow` for error handling.

To enable all features add this to your `Cargo.toml`:

```toml
# features for dbc-codegen `messages.rs` file
[features]
default = ["debug", "arb", "range_checked", "std"]
arb = ["arbitrary"]
debug = []
range_checked = []
std = []
```

### Field/variant rename rules

If some field name starts with a non-alphabetic character or is a Rust keyword then it is prefixed with `x`.

For example:

```
VAL_ 512 Five 0 "0Off" 1 "1On" 2 "2Oner" 3 "3Onest";
```

…is generated as:

```rust
pub enum BarFive {
    X0off,
    X1on,
    X2oner,
    X3onest,
    _Other(bool),
}
```

`Type` here:

```
SG_ Type : 30|1@0+ (1,0) [0|1] "boolean" Dolor
```

…conflicts with the Rust keyword `type`. Therefore we prefix it with `x`:

```rust
pub fn xtype(&self) -> BarType {
    match self.xtype_raw() {
        false => BarType::X0off,
        true => BarType::X1on,
        x => BarType::_Other(x),
    }
}
```

## License

Licensed under either of

 - Apache License, Version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
 - MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)

at your option.

### Contribution

Unless you explicitly state otherwise, any contribution intentionally
submitted for inclusion in the work by you, as defined in the Apache-2.0
license, shall be dual licensed as above, without any additional terms or
conditions.
