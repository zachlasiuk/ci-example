pipeline {
  agent any
  stages {
    stage('error') {
      steps {
        sh '''echo \'hi, this is my first step\'
'''
      }
    }
    stage('test') {
      agent {
        docker {
          image 'test-bare-metal-env:latest'
        }

      }
      steps {
        sh '''# Verify where we are
ls ~/arm-tools/

# Source setup code
. /arm-tools/init.sh


# Run test
python model_run.py localhost 7000 /home/IOTKit_ARMv8MBL_test.axf output.txt

cat output.txt

# Convert to junit output'''
      }
    }
  }
}