# ci-example

## Machine Setup
Tested on a new Linux machine, Ubuntu 18.04. Do a apt-get update to make sure your system is up to date:
- sudo apt-get update

## Install Docker
We will need Docker installed to work properly. Run the following command to quickly and easily install Docker:
```bash
curl -fsSL test.docker.com -o get-docker.sh && sh get-docker.sh
sudo usermod -aG docker $USER
```
The second command adds your user to the docker group to enable it to be used without sudo. After running, log out and log back into your machine for it to properly take effect. After logging back in run a simple docker command to make sure it is working correctly:
```bash
docker run hello-world
```


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


