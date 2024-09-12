import { useEffect, useState } from 'react';
import { StyleSheet, View, Text } from 'react-native';
import { hello } from 'react-native-quack';

export default function App() {
  const [result, setResult] = useState<string>('');

  useEffect(() => {
    hello().then(setResult);
  }, []);

  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
