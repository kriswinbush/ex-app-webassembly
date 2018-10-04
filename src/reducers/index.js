import { combineReducers } from 'redux';

import productsReducer from './productsReducer';
import usersReducer from './usersReducer';

export default combineReducers({
    products: productsReducer,
    users: usersReducer
});