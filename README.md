# ci-example

### Machine Setup
Tested on a new Linux machine, Ubuntu 18.04, with the following packages installed:
- sudo apt-get update
- sudo apt-get install -y git zip gcc-7 g++-7 make curl libc6-i386 lib32z1 lib32stdc++6                      

## Set up Jenkins
First, install java:
```bash
sudo apt install openjdk-8-jre
```

Then install the Jenkins server itself:
```bash
wget -q -O - https://pkg.jenkins.io/debian/jenkins.io.key | sudo apt-key add -
sudo sh -c 'echo deb http://pkg.jenkins.io/debian-stable binary/ > /etc/apt/sources.list.d/jenkins.list'
sudo apt-get update
sudo apt-get install Jenkins
```

You can then navigate to the Jenkins server using a web-browser at port 8080. If running locally, navigate to ->
- localhost:8080
If running in a cloud machine, as I am, navigate to ->
- <cloud-ip-address>:8080
  
## Log into Jenkins and install plugins
After getting to the Jenkins homepage it should display a page asking to 'Unlock Jenkins' the first time. Access the secret password by catting the secret file created on install:
```bash
sudo cat /var/lib/jenkins/secrets/initialAdminPassword
```
Log in, and install the recommended plugins. Then create your admin user (make sure to remember your password!). 

Optionally, As an easier way to view the Jenkins CI pipeline visually you can install the Blue Ocean plugin which I find useful. To do so follow these steps:
- Navigate to ‘Manage Jenkins’ > ‘Plugin Manager’ via the left navigation bars or go to the url: localhost:8080/pluginManager.
- Go to the ‘Available’ tab and type in Blue Ocean. Select the top option, it will install dependencies automatically.
- Click ‘install without restart’.
- Let it install, then refresh the page upon completion and navigate back to localhost:8080. A new option on the left called ‘Blue Ocean’ should be present.


