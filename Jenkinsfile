pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh '''mkdir -p build
cd build
cmake ..
make'''
      }
    }
    stage('Test') {
      steps {
        echo 'Running fake tests'
      }
    }
  }
}