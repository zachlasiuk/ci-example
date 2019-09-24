pipeline {
  agent any
  stages {
    stage('build') {
      agent {
        docker {
          image 'build-bare-metal-env:latest'
          args '--network host'
        }

      }
      steps {
        sh '''# Build Test runner

# Source setup code
. /arm-tools/init.sh 

# Build test runner
(cd ./bare-metal && make tests)

# Verify existence of test runner code
cat ./bare-metal/tests/runners/test_mycode_runner.c'''
        sh '''# Build Test App

# Source setup code
. /arm-tools/init.sh 

# Build Test axf
(cd ./bare-metal && make build_test)

# Verify existence of test axf
cat ./bare-metal/IOTKit_ARMv8MBL_test.axf'''
        sh '''# Build Production App

# Source setup code
. /arm-tools/init.sh 

# Build Production axf
(cd ./bare-metal && make build_prod)

# Verify existence of test axf
cat ./bare-metal/IOTKit_ARMv8MBL.axf'''
      }
    }
    stage('test') {
      parallel {
        stage('bare-metal') {
          agent {
            docker {
              image 'test-bare-metal-env:latest'
              args '--network host'
            }

          }
          post {
            always {
              junit '**/result.xml'

            }

          }
          steps {
            sh '''# make results directory
mkdir outputs/'''
            sh '''# Verify where we are
ls
ls /
ls /home/
ls /arm-tools/

# Source setup code
. /arm-tools/init.sh

# Kill all other running instances
pkill FVP_MPS2_Cortex
#/arm-tools/Cortex-M33-FVP/FVP_MPS2_Cortex-M33 -C fvp_mps2.DISABLE_GATING=1 -C fvp_mps2.platform_type=1 --cadi-server &sleep 2s

# Run test
python bare-metal/model_run.py localhost 7000 /home/IOTKit_ARMv8MBL_test.axf outputs/output.test

# Verify test output exists
cat outputs/output.test'''
            sh '''# Convert to junit output
python /home/unity_to_junit.py outputs/
ls
cat result.xml

'''
          }
        }
        stage('linux') {
          agent {
            docker {
              image 'test-linux-env:latest'
            }

          }
          post {
            always {
              junit '**/result.xml'

            }

          }
          steps {
            sh '''# make results directory
mkdir outputs/'''
            sh '''# Run test
ls linux/
ls linux/test/
ls linux/src

python -m pytest --junitxml=outputs/output.test linux/test/test.py

# Verify test output exists
cat outputs/output.test'''
            sh '''# Rename test output for Jenkins to find it
cp outputs/output.test result.xml
'''
          }
        }
      }
    }
  }
}