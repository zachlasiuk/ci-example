# ci-example

This readme will walk you through how to reproduce this example code yourself.

## Machine Setup
Tested on a new Linux machine, Ubuntu 18.04. Do a apt-get update to make sure your system is up to date:
- sudo apt-get update

## Install Docker
We will need Docker installed to work properly. Run the following command to quickly and easily install Docker:
```bash
curl -fsSL test.docker.com -o get-docker.sh && sh get-docker.sh
sudo usermod -aG docker $USER
sudo usermod -aG docker jenkins
```
The second command adds your user to the docker group to enable it to be used without sudo. The third command adds the jenkins user to the docker group so it also has permissions to run docker without sudo. After running, log out and log back into your machine for it to properly take effect. After logging back in run a simple docker command to make sure it is working correctly:
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

## Install Arm tools 
With Jenkins and Docker squared away let's turn to installing the primary tools from Arm in this CI example: Arm Fast Models (FMs) and Arm Compiler 6 (AC6). It is not really 'installing' in the traditional sense as we will just be downloading the tarballs for AC6 and FMs. Placing the tarballs next to the Dockerfiles that need them will enable the Dockerfile to install it in its own image, handeling all the installation and setup itself.

### Obtain Arm Compiler 6
You can download the most recent Arm Compiler 6 from the Arm website:
https://developer.arm.com/tools-and-software/embedded/arm-compiler/downloads/version-6
Grab the Linx version. This should download a tarball named:
DS500-BN-00026-r5p0-16rel0.tgz
Note you do NOT need to untar the package; Docker will automatically handle that in its environment. 

Get that tarball into your machine if in the cloud, then place in the correct location. The docker container charged with builds will need the compiler, so place this tarball in this specific directory so the Build Dockerfile can find it:
/ci-example/docker-environments/BUILD-bare-metal-env/

Then verify you can build the dockerfile by running this build command:
```bash
docker build --build-arg AC_DIR=./ --build-arg AC_INSTALL=DS500-BN-00026-r5p0-16rel0.tgz -t build-bare-metal-env:latest .
```
After this build, if you run ```docker images``` you will be able to see the 'build-bare-metal-env:latest' image availible with AC6 compiled inside it.

* Note: You must build the docker container manually as Jenkins performs a 'docker pull'. This method is great for more robust set ups where the machine with Jenkins running is connected to a centeral hub where Dockerfiles of maintained building/testing environments are located. However, for simple systems like this example you need to rebuild the Dockerfiles manually outside Jenkins on your machine upon a change in the image you want to propogate to your CI run environments. You can explore giving Jenkins a Dockerfile instead of a Docker image to see if that works better for your setup.

### Obtain Arm Fast Models
You can download the most recent Arm Fast Models package from the Arm website (you may need to signin/create an Arm Developer account to download the tarball):
https://developer.arm.com/tools-and-software/simulation-models/fast-models
Grab the Linx version labeled 'Fast Models 11.10 Evaluation Package'. This should download a tarball named:
FastModels_11-10-022_Linux64.tgz
As before, you do NOT need to untar the package; Docker will automatically handle that in its environment. 

Again, place this tarball in this specific directory so the Test Dockerfile can find it:
/ci-example/docker-environments/TEST-base-metal-env/

Following the same proceedure, download the specific Fast Models system based off the Cortex-M33 and place it in the same directory. You can download it here:
https://developer.arm.com/tools-and-software/simulation-models/fixed-virtual-platforms
and downlaod the 'Cortex-M33 FVP' Linux version.
FVP_MPS2_Cortex-M33_11.10_22.tgz

Place that tgz in the same directory:
/ci-example/docker-environments/TEST-base-metal-env/


Then verify you can build the dockerfile by running this build command:
```bash
docker build -t test-bare-metal-env:latest .
```
After this build, if you run ```docker images``` you will be able to see the 'test-bare-metal-env:latest' image availible with FMs compiled inside it.

* Note: Same with this docker image as above; you must build the docker container manually before running with Jenkins for Jenkins to identify it properly.

### Obtain Arm Licenses
To obtain trail license for both tools please e-mail license.support@arm.com and request a 30 day trial license for Arm Compiler 6 (standalone) and Fast Models, specifing you are using the Cortex-M33 FVP and need both an FVP license and a full Fast Models license (to take advantage of scripting capabilities in the product used in this CI example). The response will be a Serial Number which allows you to create your own license by following the steps below.

## Build Docker environemnts
If you followed the steps above you will have already built the environments for:
- Building the bare-metal software
- Testing the bare-metal software

We need to build the environment for Testing the Linux-based software in python. Luckily everything needed is self-contained in a Dockerfile, so simply navigate to this directory and build the dockerfile:
```bash
cd ci-example/docker-environments/TEST-linux-env/
docker build -t test-linux-env:latest .
```

Upon completion, running a ```docker images``` command should output at least 3 images:
```bash
REPOSITORY                                                 TAG                 IMAGE ID            CREATED             SIZE
test-linux-env                                             latest              0552797b0a8e        2 minutes ago       424MB
test-bare-metal-env                                        latest              9e4a8f178966        9 minutes ago       2.13GB
build-bare-metal-env                                       latest              a4a9a937b1b2        37 minutes ago      1.84GB
```

## Run Pipeline
Connect to your fork

