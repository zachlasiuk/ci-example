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
ls
pwd
ls ~
cd ~
ls
ls ~/arm-tools/

# Source setup code
source /arm-tools/init.sh

# Start model
/home/Cortex-M33-FVP/FVP_MPS2_Cortex-M33 -C fvp_mps2.DISABLE_GATING=1 -C fvp_mps2.platform_type=1 --cadi-server &

# Run test
python /home/model_run.py localhost 7000 /home/IOTKit_ARMv8MBL_test.axf output.test

cat output.txt

# Convert to junit output'''
      }
    }
  }
}