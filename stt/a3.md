## Assignment 3
### Software Tools and Technologies
>
    Name : Ravish Ranjan
    Course : MCA
    Semester : 1st semester

### Que 1
1. creating batch file with my name and roll no and implementing logic.
>
    touch ravi_45.sh

![alt text](image.png)
---
2. checking property of file
>
    ls -l ravi_45.sh
![alt text](image.1.png)
---
3. making file executable
>
    chmod +x ravi_45.sh
![alt text](image.2.png)
---
4. getting starting 20 lines of file
>
    head -n 20 ravi_45.sh
![alt text](image.3.png)
---
5. checking syntax of file
>
    bash -n ravi_45.sh
![alt text](image.4.png)
---
6. Positional arguments run
>
    ./ravi_45.sh "Ravish Ranjan" 45
![alt text](image.5.png)
---
7. Interactive run
>
    ./ravi_45.sh
![alt text](image.6.png)
---
8. Invalid rollno run
>
    ./ravi_45.sh "Ravish Ranjan" 45a
![alt text](image.7.png)