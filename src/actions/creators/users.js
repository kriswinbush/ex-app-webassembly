import * as actions from '../types';

export const updateUsers = (newUser) => {
  console.log(newUser)
    //really only have to call dispatch to do async calls
    return {
      type: actions.UPDATE_USERS,
      payload: {
        users: newUser
      }
    };
}