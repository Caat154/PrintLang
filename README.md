
Simple Script Language in C
A minimalist scripting language implemented in a single C file.

📜 Description
This is a simple interpreter for a custom scripting language written in C.
It reads commands from the user, interprets them, and executes actions like printing to the console, writing to a file, and (experimentally) creating PNG images.

✅ Features
✔ Console Output (out:) – Print text to the console.
✔ File Writing (file:) – Save text to a file.
✔ (Experimental) PNG Output (png:) – Attempt to generate an image with text.

🚧 Note: PNG generation is not fully implemented yet.

🔧 Installation & Usage
1️⃣ Clone the Repository

git clone https://github.com/your_username/simple-script-lang.git
cd simple-script-lang
2️⃣ Download Dependencies
Download stb_image_write.h
Place it in the same directory as main.c.
3️⃣ Compile the Code
gcc main.c -o mylang.exe
4️⃣ Run the Interpreter
./mylang.exe
🚀 Available Commands
Command Syntax	Description
out: "Hello"	Prints text to the console.
file: "output.txt" "Hello"	Writes text to a file.
png: "output.png" "Hello"	(WIP) Creates an image with text.
exit	Exits the interpreter.

