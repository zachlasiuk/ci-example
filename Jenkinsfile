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
          args '--network host'
        }

      }
      steps {
        sh '''# Verify where we are
ls
ls /
ls /home/
ls /arm-tools/

# Source setup code
. /arm-tools/init.sh

# start model running
#/arm-tools/Cortex-M33-FVP/FVP_MPS2_Cortex-M33 -C fvp_mps2.DISABLE_GATING=1 -C fvp_mps2.platform_type=1 --cadi-server

# Run test
python bare-metal/model_run.py localhost 7000 /home/IOTKit_ARMv8MBL_test.axf output.txt

cat output.txt

# Convert to junit output'''
      }
    }
  }
}