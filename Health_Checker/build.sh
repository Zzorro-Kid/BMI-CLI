#!/bin/bash

g++ main.cpp -o health

cat <<EOF > run_again.sh
#!/bin/bash
./health
echo
read -p "Press Enter to exit..."
EOF

# Make the new script executable
chmod +x run_again.sh

echo "File run_again.sh created and ready to start ;)"
