import * as UE from 'ue'
import { argv } from "puerts";

const GameInstance = argv.getByName("GameInstance") as UE.GameInstance;

console.warn("JavaScript Entry Point Started!");