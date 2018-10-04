import * as actions from '../actions/types'
let initialState = "";

export default (state = initialState, action ) => {
    switch(action.type) {
        case actions.UPDATE_USERS:
            return action.payload.users;
        default: 
            return state;
    }
}