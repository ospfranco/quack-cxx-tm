import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  hello(): Promise<string>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('Quack');
