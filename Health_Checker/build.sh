#!/bin/bash

gcc main.c -o health

cat <<EOF > run_again.sh
#!/bin/bash
./health
echo
read -p "Нажмите Enter для выхода..."
EOF

chmod +x run_again.sh

echo "File run_again.sh created and ready to start ;)"