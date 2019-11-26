/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow
 */

import React, { Component} from 'react';
import {
  NativeModules,
  View,
  Button,
  TextInput
} from 'react-native';


import md5 from './MD5';


function threeFor(){
  let ret = 0;
  for(let i = 0;i<1000 ; i++){
    for(let j = 0;j<1000;j++){
      for(let k = 0;k<100;k++){
        ret += k;
      }
    }
  }
  return ret;
}
export default class App extends Component {

  constructor(props) {
    super(props);
    this.text = '';
  }


  render() {
    return (
      <View>


        <TextInput
          placeholder={'输入加密字符串'}
            onChangeText={(text) => {
          this.text = text;
        }}/>

        <Button title={'C++'} onPress={() => {
          let start = new Date().getTime();
          NativeModules.HelloCxxModule.md5(this.text, (s='') => {
              let end = new Date().getTime();
              let result = `result: ${s} \n time: ${end - start}`
              alert(result)
            }
          );
        }}/>


        <Button title={'js'} onPress={() => {
          let start = new Date().getTime();
          let s = md5(this.text);
          let end = new Date().getTime();
          let result = `result: ${s} \n time: ${end - start}`
          alert(result)
        }}/>

        <Button title={'C++ testSpeed'} onPress={() => {
          let start = new Date().getTime();
          NativeModules.HelloCxxModule.testSpeed(null, (s='') => {
              let end = new Date().getTime();
              let result = `result: ${s} \n time: ${end - start}`
              alert(result)
            }
          );
        }}/>

        <Button title={'js testSpeed'} onPress={() => {
          let start = new Date().getTime();
          let s = threeFor();
          let end = new Date().getTime();
          let result = `result: ${s} \n time: ${end - start}`
          alert(result)
        }}/>

        <Button title={'global c++'} onPress={() => {
          alert(global.nativeTest.runTest())
        }}/>


      </View>
    );
  };

}


