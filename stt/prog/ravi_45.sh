name="$1"
rollno="$2"
if [ -z "$name"]; then read -p "Enter your name : name
fi
name=$(echo "$name" | xargs)
if [ -z "$rollno" ]; then
read -p "Enter your rollno : " rollno
fi
if! [[ "$rollno" =~ ^[0-9]+$ ]]; then
echo "ERROR: Roll number must be numeric" >&2
exit 2
fi
echo "Student: $name"
echo "Roll $rollno"
