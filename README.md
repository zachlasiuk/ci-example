# ci-example

### Machine Setup
Tested on an Linux machine, Ubuntu 18.04, with the following packages installed:
- sudo apt-get update
- sudo apt-get install -y git zip gcc-7 g++-7 make curl libc6-i386 lib32z1 lib32stdc++6                      

## Set up Jenkins
First, install java:
```sudo apt install openjdk-8-jre```

Then install the Jenkins server itself:
```wget -q -O - https://pkg.jenkins.io/debian/jenkins.io.key | sudo apt-key add -
sudo sh -c 'echo deb http://pkg.jenkins.io/debian-stable binary/ > /etc/apt/sources.list.d/jenkins.list'
sudo apt-get update
sudo apt-get install Jenkins```

Yo
sdf
